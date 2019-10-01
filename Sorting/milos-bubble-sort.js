function BUBBLE_SORT(l) {
    let swapp;
    let n = l.length - 1;
    do {
        swapp = false;
        for (let i = 0; i < n; i++) {
            if (l[i] > l[i + 1]) {
                const temp = l[i];
                l[i] = l[i + 1];
                l[i + 1] = temp;
                swapp = true;
            }
        }
    } while (
        swapp
    );

    return l;
}

const list = [4, 2, 3, 1, 5];

console.log(BUBBLE_SORT(list));
