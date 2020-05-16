foo = int(input("Enter a positive number to calculate its Fibonacci: "))

def fib(bar):
    if bar < 2:
        return bar
    return fib(bar-1) + fib(bar-2)

print(fib(foo))
