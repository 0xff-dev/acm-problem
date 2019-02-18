CREATE FUNCTION getNthSalary(N INT) RETURNS INT
BEGIN
    DECLARE M INT;
    SET M = N -1;
    RETURN(
        # 自己写的非null的结果, 对mysql 的函数还是不理解啊
        SELECT IFNULL((SELECT Salary FROM Employee ORDER BY Salary DESC LIMIT M,1), NULL)
    );
END;
