# Write your MySQL query statement below
DELETE FROM person 
WHERE id NOT IN (
    SELECT id FROM 
    (
        SELECT MIN(id) AS id 
        FROM person 
        GROUP BY email) 
    AS id);
