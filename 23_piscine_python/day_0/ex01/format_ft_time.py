from datetime import datetime
import time as time

now = datetime.now()

full_date = now.strftime("%B %-d, %Y")
total_seconds = time.time()
short_date = now.strftime("%b %-d %Y")

print(f"Seconds since {full_date}: {total_seconds:,}", end=" ")
print(f"or {total_seconds:.2e} in scientific notation\n{short_date}")
