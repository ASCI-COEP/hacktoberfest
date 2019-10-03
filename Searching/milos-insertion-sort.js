function INSERTION_SORT(list) {
    const len = list.length;
    for (let i = 1; i < len; i++) {
        if (list[i] < list[0]) {
            list.unshift(list.splice(i, 1)[0]);
        } else if (list[i] > list[i - 1]) {
            continue;
        } else {
            for (let j = 1; j < i; j++) {
                if (list[i] > list[j - 1] && list[i] < list[j]) {
                    list.splice(j, 0, list.splice(i, 1)[0]);
                }
            }
        }
    }
    return list;
}

const list = [4, 2, 3, 1, 5];

console.log(INSERTION_SORT(list));