/* 세그먼트트리(SegmentTree)

자세한 설명 보려면 https://smallpants.tistory.com/123

*/

#include <iostream>
#include <vector>

std::vector<int> arr{ 1, 2, 3, 4, 5 };
std::vector<int> SegmentTree;

int Make_SegmentTree(int Node, int Start, int End)
{
    if (Start == End) return SegmentTree[Node] = arr[Start];

    int Mid = (Start + End) / 2;
    int Left_Result = Make_SegmentTree(Node * 2, Start, Mid);
    int Right_Result = Make_SegmentTree(Node * 2 + 1, Mid + 1, End);
    SegmentTree[Node] = Left_Result + Right_Result;

    return SegmentTree[Node];
}

int Sum(int Node, int Start, int End, int Left, int Right)
{
    if (Left > End || Right < Start) return 0;
    if (Left <= Start && End <= Right) return SegmentTree[Node];

    int Mid = (Start + End) / 2;
    int Left_Result = Sum(Node * 2, Start, Mid, Left, Right);
    int Right_Result = Sum(Node * 2 + 1, Mid + 1, End, Left, Right);
    return Left_Result + Right_Result;
}

void Update_SegmentTree(int Node, int Start, int End, int Index, int Diff)
{
    if (Index < Start || Index > End) return;
    SegmentTree[Node] = SegmentTree[Node] + Diff;

    if (Start != End)
    {
        int Mid = (Start + End) / 2;
        Update_SegmentTree(Node * 2, Start, Mid, Index, Diff);
        Update_SegmentTree(Node * 2 + 1, Mid + 1, End, Index, Diff);
    }
}

int main(void)
{
    int N = arr.size();

    // Make
    int Tree_Height = (int)ceil(log2(N));
    int Tree_Size = (1 << (Tree_Height + 1));
    SegmentTree.resize(Tree_Size);
    Make_SegmentTree(1, 0, N - 1);

    // Sum 구하기
    int sum = Sum(1, 0, N - 1, 1, 2); // 배열 index 1 ~ 2의 합인 5 구하기
    std::cout << sum << '\n';

    // Update
    int Index = 1;
    int Value = 5;
    int Diff = Value - arr[Index];
    Update_SegmentTree(1, 0, N - 1, Index, Diff);
}