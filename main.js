let x = new Array();

x.push(1, 2, 3, 4, 5, 6, 7, 8, 9);

let y = x.filter((value, index) => {
    return value > 5;
})