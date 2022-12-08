// survivor.cpp
// Implement any helper functions here. Do not modify the survivor.h file
// Your name:
// Your perm number:
#include "survivor.h"
#include <iostream>
#include <vector>
using namespace std;

int countVotes(Parchment *validVotes, string candidate)
{
     if (validVotes == nullptr)
     {
          return 0;
     }
     if (validVotes->vote == candidate)
     {
          return 1 + (countVotes(validVotes->next, candidate));
     }
     else
     {
          return (countVotes(validVotes->next, candidate));
     }
}

string votedOut(Parchment *validVotes)
{
     Parchment *currVote = validVotes; // creating node to iterate

     int maxVotes = 0;          // max for comparing
     string currentWinner = ""; // person who has most votes, set when max is beat
     while (currVote != nullptr)
     {
          if (countVotes(validVotes, currVote->vote) > maxVotes)
          {
               maxVotes = countVotes(validVotes, currVote->vote);
               currentWinner = currVote->vote;
          }
          currVote = currVote->next;
     }
     return currentWinner;
}
Parchment *tallyTheVote(Parchment *votingUrn, HiddenImmunityIdol *idolUsed)
{
     if (votingUrn == nullptr)
     {
          return nullptr;
     }
     // need to write edge case for if first or last node of voting urn has to be deleted

     if (votingUrn->vote == idolUsed->target)
     {
          Parchment *head = votingUrn;
          votingUrn = votingUrn->next;
          delete head;
     }

     // else if (votingUrn->next->vote == idolUsed->target)
     // {
     //      Parchment *toRemove = votingUrn->next;
     //      votingUrn->next == votingUrn->next->next;
     //      delete toRemove;
     // }

     tallyTheVote(votingUrn->next, idolUsed);
     return votingUrn;
}