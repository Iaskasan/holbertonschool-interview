#!/usr/bin/python3
"""Compute log metrics from stdin."""

import re
import sys


VALID_CODES = (200, 301, 400, 401, 403, 404, 405, 500)
LINE_RE = re.compile(
    r"^\d{1,3}(?:\.\d{1,3}){3} - \[[^\]]+\] \"GET /projects/260 HTTP/1\.1\" "
    r"(\d+) (\d+)$"
)


def print_stats(total_size, counts):
    """Print aggregated metrics."""
    print("File size: {}".format(total_size))
    for code in VALID_CODES:
        if counts[code]:
            print("{}: {}".format(code, counts[code]))


def parse_line(line):
    """Return (status_code, file_size) for valid lines, else None."""
    match = LINE_RE.match(line.strip())
    if not match:
        return None

    status_code = int(match.group(1))
    file_size = int(match.group(2))

    return status_code, file_size


def main():
    """Read stdin line by line and print metrics periodically."""
    total_size = 0
    line_count = 0
    counts = {code: 0 for code in VALID_CODES}

    try:
        for line in sys.stdin:
            line_count += 1

            parsed = parse_line(line)
            if parsed is not None:
                status_code, file_size = parsed
                total_size += file_size
                if status_code in counts:
                    counts[status_code] += 1

            if line_count % 10 == 0:
                print_stats(total_size, counts)
    except KeyboardInterrupt:
        print_stats(total_size, counts)
        return

    if line_count % 10 != 0:
        print_stats(total_size, counts)


if __name__ == "__main__":
    main()
