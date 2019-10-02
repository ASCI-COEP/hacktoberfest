var a = [
    4,
    8,
    13,
    17,
    19,
    22,
    25,
    35,
    39,
    41,
    49,
    53,
    59,
    67,
    69,
    75,
    78,
    83,
    90,
    99
];

function SEARCH_ARRAY(searchNum) {
    var position = Search(a, parseInt(searchNum));

    if (position != -1)
        console.log('The number is in position ' + (parseInt(position) + 1));
    else console.log('The number is not found');
}

// Search "theArray" for the specified "key" value
function Search(theArray, key) {
    for (var n = 0; n < theArray.length; ++n) if (theArray[n] == key) return n;

    return -1;
}

console.log(SEARCH_ARRAY(83));
