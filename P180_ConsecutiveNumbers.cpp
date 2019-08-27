# Write your MySQL query statement below
SELECT DISTINCT ConsecutiveNums
FROM (
    SELECT
        L1.Num AS ConsecutiveNums
    FROM Logs L1, Logs L2
    WHERE 
        L2.Id BETWEEN L1.Id-2 AND L1.ID AND
        L1.Num = L2.Num
    GROUP BY
        L1.Id,
        L1.Num
    HAVING COUNT(L2.Num)=3
) AS T1
