-- Implement your solution here
WITH RECURSIVE all_row AS (
SELECT ROW_NUMBER() OVER (ORDER BY l) AS rn, l AS left, r AS right FROM segments
),

work_row (rn, left, right, len) AS (
   SELECT 0, 0, 0, 0
   UNION
   SELECT all_row.rn, 
   CASE 
   WHEN all_row.left <= work_row.right THEN work_row.left
   ELSE all_row.left
   END AS left,

   CASE 
   WHEN all_row.left <= work_row.right THEN MAX(work_row.right, all_row.right)
   ELSE all_row.right
   END AS right,

   all_row.right - all_row.left - 
   (MAX(0, MIN(all_row.right, work_row.right) - 
    MAX(all_row.left, work_row.left))) AS len
    FROM
    all_row, work_row
    WHERE all_row.rn = work_row.rn + 1
)

SELECT SUM(len) FROM work_row
