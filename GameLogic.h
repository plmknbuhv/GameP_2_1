#pragma once

typedef struct _pos
{
    int x;
    int y;

    bool operator == (const _pos& other) const
    {
        return (x == other.x && y == other.y);
    }
}POS, * PPOS;

void Init();
