-- 计算器类，用于构建和解析表达式
require("TerminalExpression")
require("NonterminalExpression")

Calculator = {}

function Calculator.calculate(expression)
    local endExpre = Calculator.createExpressionTree(expression, 1, #expression)
    return endExpre:interpret()
end

function Calculator.findSplit(expression, start, ended)
    local tag = -1
    if expression:sub(start, start) == '(' and expression:sub(ended, ended) == ')' then
        start = start + 1
        ended = ended - 1
    end
    local isInBracket = 0
    local moreGrade = 0
    for i = start, ended do
        if expression:sub(i, i) == '(' then
            isInBracket = isInBracket + 1
        elseif expression:sub(i, i) == ')' then
            isInBracket = isInBracket - 1
        end
        if (expression:sub(i, i) == '+' or expression:sub(i, i) == '-') and isInBracket == 0 then
            moreGrade = 1
            tag = i
        elseif (expression:sub(i, i) == '*' or expression:sub(i, i) == '/') and moreGrade == 0 and isInBracket == 0 then
            tag = i
        end
    end
    return tag
end

function Calculator.createExpressionTree(expression, start, ended)
    local ptree
    local substr = expression:sub(start, ended)
    local num = tonumber(substr)
    if num then
        ptree = NumberExpr:new(num)
    else
        local tag = Calculator.findSplit(expression, start, ended)
        if tag < 0 then
            -- 处理括号内的数字
            local s = string.gsub(string.gsub(substr, '%(', ''), '%)', '')
            num = tonumber(s)
            ptree = NumberExpr:new(num)
        else
            if expression:sub(tag, tag) == '+' then
                ptree = AdditionExpr:new(
                    Calculator.createExpressionTree(expression, start, tag - 1),
                    Calculator.createExpressionTree(expression, tag + 1, ended)
                )
            elseif expression:sub(tag, tag) == '-' then
                ptree = SubtractionExpr:new(
                    Calculator.createExpressionTree(expression, start, tag - 1),
                    Calculator.createExpressionTree(expression, tag + 1, ended)
                )
            elseif expression:sub(tag, tag) == '*' then
                ptree = MultiplicationExpr:new(
                    Calculator.createExpressionTree(expression, start, tag - 1),
                    Calculator.createExpressionTree(expression, tag + 1, ended)
                )
            elseif expression:sub(tag, tag) == '/' then
                ptree = DivisionExpr:new(
                    Calculator.createExpressionTree(expression, start, tag - 1),
                    Calculator.createExpressionTree(expression, tag + 1, ended)
                )
            end
        end
    end
    return ptree
end