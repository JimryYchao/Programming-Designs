package ChainOfResponsibility

import "fmt"

type ConsoleLogger struct {
	*BaseLogger
}

func NewConsoleLogger(level int) *ConsoleLogger {
	c := ConsoleLogger{}
	c.BaseLogger = NewBaseLogger(level, &c)
	return &c
}

// Write 写入控制台日志
func (l *ConsoleLogger) Write(message string) {
	fmt.Println("Console: " + message)
}

type WarningLogger struct {
	*BaseLogger
}

func NewWarningLogger(level int) *WarningLogger {
	w := WarningLogger{}
	w.BaseLogger = NewBaseLogger(level, &w)
	return &w
}

// Write 写入警告日志
func (l *WarningLogger) Write(message string) {
	fmt.Println("Warning: " + message)
}

type ErrorLogger struct {
	*BaseLogger
}

func NewErrorLogger(level int) *ErrorLogger {
	e := ErrorLogger{}
	e.BaseLogger = NewBaseLogger(level, &e)
	return &e
}
func (l *ErrorLogger) Write(message string) {
	fmt.Println("Error: " + message)
}
