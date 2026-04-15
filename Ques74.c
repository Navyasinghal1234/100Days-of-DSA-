//Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.
#include <stdio.h>
#include <string.h>]
#define MAX 1000
#define NAME_LEN 50
int main() {
    int n;
    char votes[MAX][NAME_LEN];
    char unique[MAX][NAME_LEN];
    int count[MAX] = {0};
    int uniqueCount = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(votes[i], unique[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(unique[uniqueCount], votes[i]);
            count[uniqueCount] = 1;
            uniqueCount++;
        }
    }
    int maxVotes = -1;
    char winner[NAME_LEN];

    for (int i = 0; i < uniqueCount; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        }
        else if (count[i] == maxVotes) {
            if (strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }
    printf("%s %d\n", winner, maxVotes);

    return 0;
}
