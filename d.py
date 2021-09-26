import sys
import sqlite3

con = sqlite3.connect(':memory:', isolation_level=None)
cur = con.cursor()
cur.executescript("""
PRAGMA trusted_schema = OFF;
PRAGMA journal_mode = OFF;
PRAGMA synchronous = OFF;
PRAGMA temp_store = memory;
PRAGMA secure_delete = OFF;

CREATE TABLE wood(len INT);
CREATE INDEX wood_index ON wood(len);
""")

L, Q = map(lambda x: int(x), sys.stdin.readline().split())
cur.execute("INSERT INTO wood VALUES(?)", (0, ))
cur.execute("INSERT INTO wood VALUES(?)", (L, ))

for _ in range(Q):
    c, x = map(lambda x: int(x), sys.stdin.readline().split())
    if c == 1:
        cur.execute("INSERT INTO wood VALUES(?)", (x, ))
    else:
        cur.execute("SELECT MAX(len) FROM wood where len < ?", (x,))
        left = cur.fetchall()[0][0]
        cur.execute("SELECT MIN(len) FROm wood WHERE len > ?", (x,))
        right = cur.fetchall()[0][0]
        print(right - left)
