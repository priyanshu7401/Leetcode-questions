CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE M INT;
  SET M=N-1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT salary 
             from Employee 
             ORDER BY salary DESC limit 1 OFFSET M
      
  );
END