SELECT t1.col1, 
    (DISTINCT t2.col2),
    COUNT(DISTINCT t1.col2),
    CASE 
        WHEN t1.col1 > 90 THEN 'Excellent'
        WHEN t1.col1 > 80 THEN 'Good'
        WHEN t1.col1 > 70 THEN 'Average'
        ELSE 'Needs Improvement'
    END
FROM t1
JOIN t2 ON t1.col = t2.col
WHERE condition
GROUP BY t1.col1, t2.col2, ...
HAVING condition
ORDER BY t1.col1 [ASC|DESC]
LIMIT number OFFSET number;

