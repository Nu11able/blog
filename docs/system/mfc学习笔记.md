## tips

### 怎么获得透明画刷
```C++
CBrush* pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));

//例子：
CClientDC dc(this);
CBrush* pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
CBrush* pOldBrush = dc.SelectObject(pBrush);
dc.Rectangle(CRect(lbtnd, point));
dc.SelectObject(pOldBrush);
```

