package Observer

import "sync"

// AccountData 账户数据
type AccountData struct {
	accounts map[string]string
	changer  IChangeManager
}

var accountInstance *AccountData
var accountOnce sync.Once

// GetAccountData 获取账户数据实例
func GetAccountData() *AccountData {
	accountOnce.Do(func() {
		accountInstance = &AccountData{
			accounts: make(map[string]string),
			changer:  GetLoggerManager(),
		}
	})
	return accountInstance
}

// LoginAccount 登录账户
func (ad *AccountData) LoginAccount(account, password string) {
	if pwd, ok := ad.accounts[account]; ok {
		if pwd == password {
			ad.Attach(GetLoginSuccessfulObserver())
			return
		}
	}
	ad.Attach(GetLoginFailedObserver())
}

// RegisterAccount 注册账户
func (ad *AccountData) RegisterAccount(account, password string) {
	if _, ok := ad.accounts[account]; !ok {
		ad.accounts[account] = password
		ad.Attach(GetRegisterSuccessfulObserver())
	} else {
		ad.Attach(GetRegisterFailedObserver())
	}
}

// Attach 附加观察者
func (ad *AccountData) Attach(observer IObserver) {
	ad.changer.Register(ad, observer)
}

// Detach 分离观察者
func (ad *AccountData) Detach(observer IObserver) {
	ad.changer.Unregister(ad, observer)
}

// Notify 通知观察者
func (ad *AccountData) Notify() {
	ad.changer.Notify()
}
