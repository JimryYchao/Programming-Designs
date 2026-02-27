#include "change_manager.h"

// 简单变更管理器的Register方法
static void simple_register(IChangeManager* self, ISubject* subject, IObserver* observer) {
    SimpleChangeManager* cm = (SimpleChangeManager*)self;
    if (cm->count < cm->capacity) {
        // 检查观察者是否已存在
        for (int i = 0; i < cm->count; i++) {
            if (cm->observers[i] == observer) {
                return;
            }
        }
        cm->observers[cm->count] = observer;
        cm->count++;
    }
}

// 简单变更管理器的Unregister方法
static void simple_unregister(IChangeManager* self, ISubject* subject, IObserver* observer) {
    SimpleChangeManager* cm = (SimpleChangeManager*)self;
    for (int i = 0; i < cm->count; i++) {
        if (cm->observers[i] == observer) {
            // 移动后续观察者
            for (int j = i; j < cm->count - 1; j++) {
                cm->observers[j] = cm->observers[j + 1];
            }
            cm->count--;
            break;
        }
    }
}

// 简单变更管理器的Notify方法
static void simple_notify(IChangeManager* self) {
    SimpleChangeManager* cm = (SimpleChangeManager*)self;
    for (int i = 0; i < cm->count; i++) {
        cm->observers[i]->Update(cm->observers[i], cm->subject);
    }
}

// 创建简单变更管理器
SimpleChangeManager* create_simple_change_manager(ISubject* subject, int capacity) {
    SimpleChangeManager* cm = (SimpleChangeManager*)malloc(sizeof(SimpleChangeManager));
    if (cm == NULL) {
        return NULL;
    }
    cm->base.Register = simple_register;
    cm->base.Unregister = simple_unregister;
    cm->base.Notify = simple_notify;
    cm->subject = subject;
    cm->observers = (IObserver**)malloc(sizeof(IObserver*) * capacity);
    if (cm->observers == NULL) {
        free(cm);
        return NULL;
    }
    cm->count = 0;
    cm->capacity = capacity;
    return cm;
}

// 清空观察者
void clear_observer(SimpleChangeManager* cm) {
    cm->count = 0;
}

// DCG变更管理器的Register方法
static void dcg_register(IChangeManager* self, ISubject* subject, IObserver* observer) {
    DCGChangeManager* cm = (DCGChangeManager*)self;
    // 查找主题是否已存在
    int subject_index = -1;
    for (int i = 0; i < cm->subject_count; i++) {
        if (cm->subjects[i] == subject) {
            subject_index = i;
            break;
        }
    }
    
    if (subject_index == -1) {
        // 添加新主题
        if (cm->subject_count < cm->capacity) {
            cm->subjects[cm->subject_count] = subject;
            cm->observers[cm->subject_count] = (IObserver**)malloc(sizeof(IObserver*) * 10);
            if (cm->observers[cm->subject_count] == NULL) {
                return;
            }
            cm->observer_counts[cm->subject_count] = 0;
            subject_index = cm->subject_count;
            cm->subject_count++;
        } else {
            return;
        }
    }
    
    // 检查观察者是否已存在
    for (int i = 0; i < cm->observer_counts[subject_index]; i++) {
        if (cm->observers[subject_index][i] == observer) {
            return;
        }
    }
    
    // 添加观察者
    cm->observers[subject_index][cm->observer_counts[subject_index]] = observer;
    cm->observer_counts[subject_index]++;
}

// DCG变更管理器的Unregister方法
static void dcg_unregister(IChangeManager* self, ISubject* subject, IObserver* observer) {
    DCGChangeManager* cm = (DCGChangeManager*)self;
    for (int i = 0; i < cm->subject_count; i++) {
        if (cm->subjects[i] == subject) {
            for (int j = 0; j < cm->observer_counts[i]; j++) {
                if (cm->observers[i][j] == observer) {
                    // 移动后续观察者
                    for (int k = j; k < cm->observer_counts[i] - 1; k++) {
                        cm->observers[i][k] = cm->observers[i][k + 1];
                    }
                    cm->observer_counts[i]--;
                    break;
                }
            }
            break;
        }
    }
}

// DCG变更管理器的Notify方法
static void dcg_notify(IChangeManager* self) {
    DCGChangeManager* cm = (DCGChangeManager*)self;
    for (int i = 0; i < cm->subject_count; i++) {
        for (int j = 0; j < cm->observer_counts[i]; j++) {
            cm->observers[i][j]->Update(cm->observers[i][j], cm->subjects[i]);
        }
    }
}

// 全局DCG变更管理器实例
static DCGChangeManager* dcg_instance = NULL;

// 获取DCG变更管理器实例
DCGChangeManager* get_dcg_change_manager() {
    if (dcg_instance == NULL) {
        dcg_instance = (DCGChangeManager*)malloc(sizeof(DCGChangeManager));
        if (dcg_instance == NULL) {
            return NULL;
        }
        dcg_instance->base.Register = dcg_register;
        dcg_instance->base.Unregister = dcg_unregister;
        dcg_instance->base.Notify = dcg_notify;
        dcg_instance->capacity = 10;
        dcg_instance->subjects = (ISubject**)malloc(sizeof(ISubject*) * dcg_instance->capacity);
        dcg_instance->observers = (IObserver***)malloc(sizeof(IObserver**) * dcg_instance->capacity);
        dcg_instance->observer_counts = (int*)malloc(sizeof(int) * dcg_instance->capacity);
        if (dcg_instance->subjects == NULL || dcg_instance->observers == NULL || dcg_instance->observer_counts == NULL) {
            free(dcg_instance->subjects);
            free(dcg_instance->observers);
            free(dcg_instance->observer_counts);
            free(dcg_instance);
            return NULL;
        }
        dcg_instance->subject_count = 0;
    }
    return dcg_instance;
}

// 日志管理器的Register方法
static void logger_register(IChangeManager* self, ISubject* subject, IObserver* observer) {
    observer->Update(observer, subject);
}

// 日志管理器的Unregister方法
static void logger_unregister(IChangeManager* self, ISubject* subject, IObserver* observer) {
    // 未实现
}

// 日志管理器的Notify方法
static void logger_notify(IChangeManager* self) {
    // 未实现
}

// 全局日志管理器实例
static LoggerManager* logger_instance = NULL;

// 获取日志管理器实例
LoggerManager* get_logger_manager() {
    if (logger_instance == NULL) {
        logger_instance = (LoggerManager*)malloc(sizeof(LoggerManager));
        if (logger_instance == NULL) {
            return NULL;
        }
        logger_instance->base.Register = logger_register;
        logger_instance->base.Unregister = logger_unregister;
        logger_instance->base.Notify = logger_notify;
    }
    return logger_instance;
}
