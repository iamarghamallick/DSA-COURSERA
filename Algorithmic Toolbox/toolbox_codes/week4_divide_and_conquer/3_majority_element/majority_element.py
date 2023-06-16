def majority_element_naive(elements):
    elements.sort()
    count, max_ele, temp, f = 1, -1, elements[0], 0
    for i in range(1, len(elements)) :
        if(temp == elements[i]) :
            count += 1
        else :
            count = 1
            temp = elements[i]

        if(max_ele < count) :
            max_ele = count
            # majority = elements[i]
            if(max_ele > len(elements)//2) :
                f = 1
                break
    if f == 1:
        # return majority
        return 1
    else :
        # return -1 
        return 0

if __name__ == '__main__':
    input_n = int(input())
    input_elements = list(map(int, input().split()))
    assert len(input_elements) == input_n
    print(majority_element_naive(input_elements))
