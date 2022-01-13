def make_set(s):
    result = set()
    for i in range(len(s)):
        for j in range(i + 1, len(s) + 1):
            result.add(s[i:j])
    return result


def lcs(s1, s2):
    max_len = 0
    max_str = ''
    for each in make_set(s1) & make_set(s2):
        if len(each) > max_len:
            max_len = len(each)
            max_str = each
    print(max_str)


a = input()
str1 = input()
str2 = input()
lcs(str1, str2)
