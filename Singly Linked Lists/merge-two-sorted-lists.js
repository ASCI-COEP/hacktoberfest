class ListNode {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

const mergeTwoLists = (l1, l2) => {
    let list = new ListNode(null);
    let aux = list;

    while (l1 && l2) {
        if (l1.val < l2.val) {
            aux.next = l1;
            l1 = l1.next;
        } else {
            aux.next = l2;
            l2 = l2.next
        }

        aux = aux.next;
    }

    if (l1) {
        aux.next = l1;
    }

    if (l2) {
        aux.next = l2;
    }

    return list.next;
};