package ChainOfResponsibility_test

import (
	. "ChainOfResponsibility"
	"testing"
)

func TestChainOfResponsibility(t *testing.T) {
	// 创建责任链
	var logger LoggerHandler = NewConsoleLogger(DEFAULT)
	warning := NewWarningLogger(WARNING)
	error := NewErrorLogger(ERROR)
	SetNextLogger(logger, warning)
	SetNextLogger(warning, error)

	// 测试不同级别的日志
	logger.Log(DEFAULT, "This is a default log")
	logger.Log(WARNING, "This is a warning log")
	logger.Log(ERROR, "This is an error log")
}
