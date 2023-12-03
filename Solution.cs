
using System;

public class Solution
{
    public int[] GetSumAbsoluteDifferences(int[] input)
    {
        int totalElements = input.Length;

        //alternatively:  input.Sum()
        int sumAllElements = 0;
        foreach (int value in input)
        {
            sumAllElements += value;
        }

        int[] sumAbsoluteDifferences = new int[totalElements];
        int sumPreceedingElements = 0;

        for (int i = 0; i < totalElements; ++i)
        {
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
