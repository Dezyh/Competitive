#include <bits/stdc++.h>

using namespace std;

#define xx first
#define yy second
#define ddown first
#define dup second
#define dleft first
#define dright second
#define pll pair<long,long>
#define vpll vector<pair<long,long>>

#define BOARD 2000000000

struct coord {
    bool center;
    long x;
    long y;
    coord(long x, long y, bool center=false) : x(x), y(y), center(center) {};

};

const vector<coord> initial = {coord(BOARD/2,BOARD/2), coord(BOARD/4,BOARD/4), coord(3*BOARD/4,BOARD/4), coord(BOARD/4,3*BOARD/4), coord(3*BOARD/4,3*BOARD/4)};

void io(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

string dart_throw(long x, long y) {
    cout << (x-BOARD/2) << ' ' << (y-BOARD/2) << endl;
    string res; cin >> res; 
    if (res == "WRONG")
        exit(0);
    return res;
}

coord find_hit() {
    for (auto coord : initial) {
        string res = dart_throw(coord.x, coord.y);
        if (res == "CENTER")
            return coord(coord.x, coord.y, true)
        if (res == "HIT")
            return {false, coord};
    }
    return {false, {-1,-1}};
}

pair<bool,pair<long,long>> board_edge_horizontal(pll hit) {
    long l, r, m;
    long re=-1, le=-1;
    // right edge
    l=hit.xx;
    r=BOARD_FULL;
    while (r >= l) {
        m = l+(r-l)/2;
        string res = dart_throw(m, hit.yy);
        if (res == MISS) {
            r = m-1;
        } else if (res == HIT) {
            l = m+1;
            re = m;
        } else {
            return {true, {-1, -1}};
        }
    }
    // left edge
    l=0;
    r=hit.xx;
    while (r >= l) {
        m = l+(r-l)/2;
        string res = dart_throw(m, hit.yy);
        if (res == MISS) {
            l = m+1;
        } else if (res == HIT) {
            r = m-1;
            le = m;
        } else {
            return {true, {-1,-1}};
        }
    }
    return {false, {le, re}};
}

pair<bool,pair<long,long>> board_edge_vertical(pll hit) {
    long l, r, m;
    long ue=-1, de=-1;
    // up edge
    l = hit.yy;
    r = BOARD_FULL;
    while (r>=l) {
        m = l+(r-l)/2;
        string res = dart_throw(hit.xx, m);
        if (res == MISS) {
            r = m-1;
        } else if (res == HIT) {
            l = m+1;
            ue = m;
        } else {
            return {true, {-1,-1}};
        }
    }
    // down edge
    l = 0;
    r = hit.yy;
    while (r >= l) {
        m = l+(r-l)/2;
        string res = dart_throw(hit.xx, m);
        if (res == MISS) {
            l = m+1;
        } else if (res == HIT) {
            r = m-1;
            de = m;
        } else {
            return {true, {-1,-1}};
        }
    }
    return {false, {de, ue}};
}

int main() {
    io();
    
    long t, a, b; 
    cin >> t >> a >> b;
    
    // shift to make all values positive
    a += BOARD_HALF;
    b += BOARD_HALF;

    while (t--) {
        // find any hit on the board
        pair<bool,pair<long,long>> hit = find_hit();
        if (hit.first) continue;

        // find some board edges using bsearch
        pair<bool,pair<long,long>> v = board_edge_vertical(hit.second);
        if (v.first) continue;
        pair<bool,pair<long,long>> h = board_edge_horizontal(hit.second);
        if (h.first) continue;

        // find the center
        long cy = v.second.ddown+(v.second.dup-v.second.ddown)/2;
        long cx = h.second.dleft+(h.second.dright-h.second.dleft)/2;

        // throw at center
        string res = dart_throw(cx, cy);
        if (res != CENTER)
            exit(0);
    }
}