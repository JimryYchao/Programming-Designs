package ChainOfResponsibility

import "fmt"

// 日志级别常量
const (
	DEFAULT = 1
	WARNING = 2
	ERROR   = 3
)

func defaultWrite(message string) {
	fmt.Println("Default Console: " + message)
}

type BaseLogger struct {
	l          LoggerHandler
	level      int
	nextLogger *LoggerHandler
}

// LoggerHandler 日志处理器接口
type LoggerHandler interface {
	Log(level int, message string)
	Write(message string)
	GetNextLogger() *LoggerHandler
}

func SetNextLogger(logger LoggerHandler, nextLogger LoggerHandler) {
	*logger.GetNextLogger() = nextLogger
}

func (h *BaseLogger) Log(level int, message string) {
	if level == h.level {
		// 调用具体实现的 Write 方法
		if logger, ok := interface{}(h).(LoggerHandler); ok {
			logger.Write(message)
		}
		return
	}
	if h.nextLogger != nil {
		(*h.nextLogger).Log(level, message)
	} else {
		defaultWrite(message)
	}
}

func (h *BaseLogger) GetNextLogger() *LoggerHandler {
	return h.nextLogger
}

// Write 写入日志（需要子类实现）
func (h *BaseLogger) Write(message string) { h.l.Write(message) }

// NewBaseLogger 创建基础日志处理器
func NewBaseLogger(level int, logger LoggerHandler) *BaseLogger {
	return &BaseLogger{
		l:          logger,
		level:      level,
		nextLogger: new(LoggerHandler),
	}
}
