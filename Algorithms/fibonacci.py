def fibonacci(n):
  if n == 0:
    return 'n/a'
  elif n == 1:
    return 0
  elif n == 2:
    return 1
  else:
    return fibonacci(n - 1) + fibonacci(n - 2)


def main():
  print(fibonacci(0))
  print(fibonacci(1))
  print(fibonacci(2))
  print(fibonacci(9))


if __name__ == "__main__":
  main()