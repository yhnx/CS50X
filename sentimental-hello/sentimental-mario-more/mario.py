from cs50 import get_int
high = 0
while high > 8 or high < 1:
   high = get_int("Height: ")
for n in range(1, high+1):
      print(" " * (high - n) + "#" * n + "  " + "#" * n)
