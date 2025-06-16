#pragma once

void Init();

typedef struct _pos
{
    int x;
    int y;

    bool operator == (const _pos& other) const
    {
        return (x == other.x && y == other.y);
    }
    _pos operator + (const _pos& other) const
    {
        return { x + other.x, y + other.y };
    }
}POS, * PPOS;
