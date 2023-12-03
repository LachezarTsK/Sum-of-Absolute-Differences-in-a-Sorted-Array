
public class Solution {

    public int[] getSumAbsoluteDifferences(int[] input) {
        final int totalElements = input.length;

        //alternatively: Arrays.stream(input).sum()
        int sumAllElements = 0;
        for (int value : input) {
            sumAllElements += value;
        }

        int[] sumAbsoluteDifferences = new int[totalElements];
        int sumPreceedingElements = 0;

        for (int i = 0; i < totalElements; ++i) {
            int numberOfPreceedingElements = i;
            int numberOfFollowingElements = totalElements - 1 - i;

            int sumFollowingElements = sumAllElements - sumPreceedingElements - input[i];

            int preceedingValuesDifferences = (input[i] * numberOfPreceedingElements) - sumPreceedingElements;
            int followingValuesDifferences = sumFollowingElements - (input[i] * numberOfFollowingElements);

            sumAbsoluteDifferences[i] = preceedingValuesDifferences + followingValuesDifferences;

            sumPreceedingElements += input[i];
        }

        return sumAbsoluteDifferences;
    }
}
