# UTF-8 Validation

Validate whether a list of integers represents a valid UTF-8 encoding.

## Prototype

```python
def validUTF8(data)
```

## Return

- `True` if `data` is a valid UTF-8 sequence
- `False` otherwise

## Notes

- A UTF-8 character can be 1 to 4 bytes long.
- Each integer in `data` represents one byte.
- Only the 8 least significant bits are considered.
- The list may contain multiple characters.

## Approach

Track how many continuation bytes are expected after a leading byte:

- `0xxxxxxx` -> single-byte character
- `110xxxxx` -> expect 1 continuation byte
- `1110xxxx` -> expect 2 continuation bytes
- `11110xxx` -> expect 3 continuation bytes
- Continuation bytes must match `10xxxxxx`

The sequence is valid only if all expected continuation bytes are consumed.
