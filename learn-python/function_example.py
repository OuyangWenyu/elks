# python函数的相关特点


def apply_async(func, args, *, callback):
    """回调函数的应用，python的函数很灵活，可以直接做函数参数"""
    # Compute the result
    result = func(*args)

    # Invoke the callback with the result
    callback(result)


def print_result(result):
    print('Got:', result)


def add(x, y):
    return x + y


apply_async(add, (2, 3), callback=print_result)

apply_async(add, ('hello', 'world'), callback=print_result)

# ----------------------------

print(all(['a', 'b', 'c', 'd']))  # 列表list，元素都不为空或0
print(all(['a', 'b', '', 'd']))
print(all([0, 1, 2, 3]))
print(all([]))
print(all(()))
