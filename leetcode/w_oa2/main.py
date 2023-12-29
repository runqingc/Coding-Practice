# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.


def predictAnswer(stockData, queries):
    # Write your code here
    ret = []
    if (len(stockData) == 0):
        return [-1 for _ in range(len(queries))]

    s = []
    right_small = [-1 for _ in range(len(stockData))]
    for i in range(len(stockData)):
        if len(s) == 0 or stockData[s[-1]] <= stockData[i]:
            s.append(i)
            continue
        while len(s) != 0 and stockData[s[-1]] > stockData[i]:
            right_small[s[-1]] = i
            s.pop()
        s.append(i)

    s.clear()

    left_small = [-1 for _ in range(len(stockData))]
    for i in list(range(len(stockData)))[::-1]:
        if len(s) == 0 or stockData[s[-1]] <= stockData[i]:
            s.append(i)
            continue
        while len(s) != 0 and stockData[s[-1]] > stockData[i]:
            right_small[s[-1]] = i
            s.pop()
        s.append(i)

    for each_query in queries:
        each_query -= 1
        if left_small[each_query] == -1 and right_small[each_query] == -1:
            ret.append(-1)
        elif left_small[each_query] == -1:
            ret.append(right_small[each_query] + 1)
        elif right_small[each_query] == -1:
            ret.append(left_small[each_query] + 1)
        elif each_query - left_small[each_query] <= right_small[each_query] - each_query:
            ret.append(left_small[each_query] + 1)
        else:
            ret.append(right_small[each_query] + 1)

    return ret

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print(predictAnswer([5, 6, 8, 4, 9, 10, 8, 3, 6, 4], [6,5,4]))

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
