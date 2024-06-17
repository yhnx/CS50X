# TODO
high = int(input("Height:"))
for n in range(high):
      for m in range(high-n):
        print(" ", end="")
      for o in range(n):
        print("#", end="")
      print("  ", end="")
      for p in range(n):
        print("#", end='')
      print("\n")
