import subprocess, datetime, os

# ── Bot emails to exclude (GitHub Actions automated commits) ─────────
BOT_EMAILS = {'action@github.com', 'github-actions[bot]@users.noreply.github.com'}

# ── Get all commit dates from THIS repo (with author email) ──────────
result = subprocess.run(
    ['git', 'log', '--format=%ad|%ae', '--date=format:%Y-%m-%d'],
    capture_output=True, text=True
)
raw_lines = result.stdout.strip().split('\n')
date_counts = {}
skipped = 0
for line in raw_lines:
    line = line.strip()
    if not line:
        continue
    try:
        parts = line.split('|', 1)
        d = parts[0]
        author = parts[1] if len(parts) > 1 else ''
        # Skip bot/automated commits
        if author in BOT_EMAILS:
            skipped += 1
            continue
        dt = datetime.date.fromisoformat(d)
        date_counts[dt] = date_counts.get(dt, 0) + 1
    except Exception:
        pass

print(f"Found {sum(date_counts.values())} commits across {len(date_counts)} days (skipped {skipped} bot commits).")

# ── Layout ────────────────────────────────────────────────────────────
today  = datetime.date.today()
WEEKS  = 53
CELL   = 11
GAP    = 2
LEFT   = 30
TOP    = 50
STEP   = CELL + GAP
WIDTH  = LEFT + (WEEKS + 1) * STEP + 12
HEIGHT = TOP + 7 * STEP + 30

# 53 weeks back, aligned to Monday
start = today - datetime.timedelta(weeks=WEEKS)
start = start - datetime.timedelta(days=start.weekday())

COLORS = ['#161b22', '#0e4429', '#006d32', '#26a641', '#39d353']
MONTHS = ['', 'Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun',
          'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec']

def color(count):
    if count == 0: return COLORS[0]
    if count == 1: return COLORS[1]
    if count <= 3: return COLORS[2]
    if count <= 6: return COLORS[3]
    return COLORS[4]

# ── Build SVG ─────────────────────────────────────────────────────────
out = []
out.append(f'<svg width="{WIDTH}" height="{HEIGHT}" viewBox="0 0 {WIDTH} {HEIGHT}" xmlns="http://www.w3.org/2000/svg">')
out.append(f'  <rect width="{WIDTH}" height="{HEIGHT}" fill="#0d1117" rx="8"/>')
out.append(f'  <text x="{WIDTH//2}" y="16" fill="#58a6ff" '
           f'font-family="Arial,sans-serif" font-size="12" '
           f'text-anchor="middle" font-weight="bold">'
           f'DSA Repo \u2014 Contribution Heatmap</text>')
out.append(f'  <line x1="{LEFT}" y1="24" x2="{WIDTH-8}" y2="24" '
           f'stroke="#21262d" stroke-width="1"/>')

# Day labels
for day_idx, label in [(1, 'Mon'), (3, 'Wed'), (5, 'Fri')]:
    y = TOP + day_idx * STEP + CELL - 2
    out.append(f'  <text x="2" y="{y}" fill="#8b949e" '
               f'font-family="Arial,sans-serif" font-size="8">{label}</text>')

# Month labels + cells
last_month   = -1
last_label_x = -999

for w in range(WEEKS + 1):
    for d in range(7):
        date = start + datetime.timedelta(weeks=w, days=d)
        if date > today:
            continue
        count = date_counts.get(date, 0)
        x = LEFT + w * STEP
        y = TOP  + d * STEP

        if d == 0 and date.month != last_month:
            last_month = date.month
            if x - last_label_x >= 22:
                out.append(f'  <text x="{x}" y="{TOP - 10}" fill="#8b949e" '
                           f'font-family="Arial,sans-serif" font-size="9">'
                           f'{MONTHS[date.month]}</text>')
                last_label_x = x

        tip = f"{count} commit{'s' if count != 1 else ''} on {date}"
        out.append(f'  <rect x="{x}" y="{y}" width="{CELL}" height="{CELL}" '
                   f'rx="2" fill="{color(count)}"><title>{tip}</title></rect>')

# Legend
lx = LEFT
ly = HEIGHT - 10
out.append(f'  <text x="{lx}" y="{ly}" fill="#8b949e" '
           f'font-family="Arial,sans-serif" font-size="8">Less</text>')
for i, c in enumerate(COLORS):
    out.append(f'  <rect x="{lx+26+i*14}" y="{ly-9}" width="{CELL}" '
               f'height="{CELL}" rx="2" fill="{c}"/>')
out.append(f'  <text x="{lx+26+5*14}" y="{ly}" fill="#8b949e" '
           f'font-family="Arial,sans-serif" font-size="8">More</text>')
out.append('</svg>')

svg = '\n'.join(out)
os.makedirs('assets', exist_ok=True)
with open('assets/contribution-graph.svg', 'w', encoding='utf-8') as f:
    f.write(svg)

print(f"SVG written: {WIDTH}x{HEIGHT}px")
