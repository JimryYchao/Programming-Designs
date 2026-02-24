// 计算器类，用于构建和解析表达式
package Interpreter

import (
	"strconv"
	"strings"
)

func Calculate(expression string) float64 {
	endExpre := createExpressionTree(expression, 0, len(expression)-1)
	return endExpre.Interpret()
}

func findSplit(expression string, start, end int) int {
	tag := -1
	if expression[start] == '(' && expression[end] == ')' {
		start++
		end--
	}
	isInBracket := 0
	moreGrade := 0
	for i := start; i <= end; i++ {
		if expression[i] == '(' {
			isInBracket++
		} else if expression[i] == ')' {
			isInBracket--
		}
		if (expression[i] == '+' || expression[i] == '-') && isInBracket == 0 {
			moreGrade = 1
			tag = i
		} else if (expression[i] == '*' || expression[i] == '/') && moreGrade == 0 && isInBracket == 0 {
			tag = i
		}
	}
	return tag
}

func createExpressionTree(expression string, start, end int) ArithmeticExpr {
	var ptree ArithmeticExpr
	substr := expression[start : end+1]
	if num, err := strconv.ParseFloat(substr, 64); err == nil {
		ptree = NewNumberExpr(num)
	} else {
		tag := findSplit(expression, start, end)
		if tag < 0 {
			// 处理括号内的数字
			s := strings.ReplaceAll(strings.ReplaceAll(substr, "(", ""), ")", "")
			num, _ := strconv.ParseFloat(s, 64)
			ptree = NewNumberExpr(num)
		} else {
			if expression[tag] == '+' {
				ptree = NewAdditionExpr(
					createExpressionTree(expression, start, tag-1),
					createExpressionTree(expression, tag+1, end),
				)
			} else if expression[tag] == '-' {
				ptree = NewSubtractionExpr(
					createExpressionTree(expression, start, tag-1),
					createExpressionTree(expression, tag+1, end),
				)
			} else if expression[tag] == '*' {
				ptree = NewMultiplicationExpr(
					createExpressionTree(expression, start, tag-1),
					createExpressionTree(expression, tag+1, end),
				)
			} else if expression[tag] == '/' {
				ptree = NewDivisionExpr(
					createExpressionTree(expression, start, tag-1),
					createExpressionTree(expression, tag+1, end),
				)
			}
		}
	}
	return ptree
}