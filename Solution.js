
/**
 * @param {number[]} input
 * @return {number[]}
 */
var getSumAbsoluteDifferences = function (input) {
    const totalElements = input.length;
    
    //alternatively: input.reduce((x, y) => x + y)
    let sumAllElements = 0;
    for (let value of input) {
        sumAllElements += value;
    }

    const sumAbsoluteDifferences = new Array(totalElements);
    let sumPreceedingElements = 0;

    for (let i = 0; i < totalElements; ++i) {
        const numberOfPreceedingElements = i;
        const numberOfFollowingElements = totalElements - 1 - i;

        const sumFollowingElements = sumAllElements - sumPreceedingElements - input[i];

        const preceedingValuesDifferences = (input[i] * numberOfPreceedingElements) - sumPreceedingElements;
        const followingValuesDifferences = sumFollowingElements - (input[i] * numberOfFollowingElements);

        sumAbsoluteDifferences[i] = preceedingValuesDifferences + followingValuesDifferences;

        sumPreceedingElements += input[i];
    }

    return sumAbsoluteDifferences;
};
