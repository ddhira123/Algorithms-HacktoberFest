const isPalindrome = string => {
    const validCharacters = "abcdefghijklmnopqrstuvwxyz".split("");
    const stringCharacters = string
        .toLowerCase()
        .split("")
        .reduce(
            (characters, character) =>
                validCharacters.indexOf(character) > -1
                    ? characters.concat(character)
                    : characters,
            []
        );
    return stringCharacters.join("") === stringCharacters.reverse().join("");
};

const _isPalindrome = string =>
    string
        .split("")
        .every((character, index) => character === string[string.length - 1 - index]);

const __isPalindrome = string => {
    const cleaned = string.replace(/\W/g, "").toLowerCase();

    return (
        cleaned ===
        cleaned
            .split("")
            .reverse()
            .join("")
    );
};

mocha.setup("bdd");
const { assert } = chai;

describe("Palindrome", () => {
    it("Should return true", () => {
        assert.equal(isPalindrome("Cigar? Toss it in a can. It is so tragic"), true);
        assert.equal(
            __isPalindrome("Cigar? Toss it in a can. It is so tragic"),
            true
        );
    });

    it("Should return false", () => {
        assert.equal(isPalindrome("sit ad est love"), false);
        assert.equal(_isPalindrome("sit ad est love"), false);
    });
});

mocha.run();
