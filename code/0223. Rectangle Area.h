/*
Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Input: A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2
Output: 45
*/

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    long long res=((long long)(C-A))*(D-B)+((long long)(G-E))*(H-F);
    if(C>E & G>A & D>F & H>B)
        return res-(min(C,G)-max(A,E))*(min(D,H)-max(F,B));
    else
        return res;
}
