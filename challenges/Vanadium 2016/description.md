Winter is coming and Victor is going to buy some new lights. In the store, lights are available in 10 colors, numbered from 0 to 9. They are connected together in a huge chain. Victor can choose any single segment of the chain and buy it.

This task would be easy if it weren't for Victor's ambition. He wants to outdo his neighbors with some truly beautiful lights, so the chain has to look the same from both its left and right sides (so that both neighbors see the same effect).

Victor is a mechanic, so after buying a segment of the chain, he can rearrange its lights in any order he wants. However, now he has to buy a chain segment that will satisfy above condition when its lights are reordered. Can you compute how many possible segments he can choose from?

Write a function:

int solution(string &S);

that, given a description of the chain of lights, returns the number of segments that Victor can buy modulo 1,000,000,007. The chain is represented by a string of digits (characters from '0' to '9') of length N. The digits represent the colors of the lights. Victor can only buy a segment of the chain in which he can reorder the lights such that the chain will look identical from both the left and right sides (i.e. when reversed).

For example, given:

    S = "02002"
the function should return 11. Victor can buy the following segments of the chain:

"0", "2", "0", "0", "2", "00", "020", "200", "002", "2002", "02002"
Note that a segment comprising a single "0" is counted three times: first it describes the subchain consisting of only the first light, then the subchain consisting of the third light and finally the subchain consisting of the fourth light. Also note that Victor can buy the whole chain ("02002"), as, after swapping the first two lights, it would become "20002", which is the same when seen from both from left and right.

Write an efficient algorithm for the following assumptions:

string S is made only of digits (0−9);
the length of string S is within the range [1..200,000].
