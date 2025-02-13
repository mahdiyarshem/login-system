void CMenus::RenderLogin(CUIRect MainView)
{
    // ایجاد یک مستطیل برای پنل ثبت نام
    CUIRect RegisterPanel;
    MainView.HSplitTop(200.0f, &RegisterPanel, &MainView);
    RegisterPanel.VMargin(100.0f, &RegisterPanel);

    // نمایش فرم ثبت نام
    static char Username[64] = "";
    static char Password[64] = "";
    static char Email[64] = "";

    UI()->DoLabel(&RegisterPanel, "Register", 20.0f, 0);
    RegisterPanel.HSplitTop(30.0f, 0, &RegisterPanel);

    UI()->DoEditBox(&Username, &RegisterPanel, "Username", 64);
    RegisterPanel.HSplitTop(10.0f, 0, &RegisterPanel);

    UI()->DoEditBox(&Password, &RegisterPanel, "Password", 64);
    RegisterPanel.HSplitTop(10.0f, 0, &RegisterPanel);

    UI()->DoEditBox(&Email, &RegisterPanel, "Email", 64);
    RegisterPanel.HSplitTop(20.0f, 0, &RegisterPanel);

    if (UI()->DoButton_Menu(&RegisterPanel, "Register", 0, &RegisterPanel))
    {
        // ذخیره اطلاعات در پایگاه داده
        RegisterUser(Username, Password, Email);
    }
}

// hamegi ro dakhele menus.cpp gharar midim va locationi barash taarif mikonim 
// zemnan UI label am bayad taarif konid
