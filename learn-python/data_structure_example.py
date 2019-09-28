"""python基本数据结构示例"""
# 数据和字符串转换
print(chr(65))
print(ord('A'))

print(int('2'))
print(str(2))

""" 字符串包含"""
string = 'helloworld'
if 'world' in string:
    print('Exist')
else:
    print('Not exist')

"""list取值"""
a_list = [1, 2, 3]
print(a_list[0])

"""enumerate函数的使用"""
seq = ['one', 'two', 'three']
for i, element in enumerate(seq):
    print(i, element)
