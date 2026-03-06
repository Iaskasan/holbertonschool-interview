# Log Parsing

Read logs from standard input and compute metrics.

## Script

- `0-stats.py`

## Input format

Each valid line must match:

`<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>`

Invalid lines are skipped.

## Output rules

- Print stats after every 10 lines read.
- Print stats again on `CTRL + C` (`KeyboardInterrupt`).
- First line: `File size: <total size>`
- Then print counts by status code in ascending order for:
  - `200, 301, 400, 401, 403, 404, 405, 500`
- Do not print status codes with count `0`.

## Run

```bash
./0-generator.py | ./0-stats.py
```
