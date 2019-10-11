const sum = (n1,n2) => n1 + n2;
const pi = 3.14;
class what{
    constructor(){
        console.log('created');
    }
}
//module.exports.sum = sum;
//module.exports.pi = pi;
//module.exports.what = what;
module.exports = {sum : sum, pi : pi, what : what}