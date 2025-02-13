void CMenus::RenderLogin(CUIRect MainView)
{
    // تنظیمات اولیه برای پنل لاگین
    CUIRect Label, UsernameBox, PasswordBox, LoginButton;
    
    // تقسیم فضای MainView به بخش‌های مختلف
    MainView.HSplitTop(20.0f, &Label, &MainView); // برچسب بالا
    MainView.HSplitTop(50.0f, &UsernameBox, &MainView); // فیلد نام کاربری
    MainView.HSplitTop(10.0f, 0, &MainView); // فاصله بین فیلدها
    MainView.HSplitTop(50.0f, &PasswordBox, &MainView); // فیلد رمز عبور
    MainView.HSplitTop(20.0f, 0, &MainView); // فاصله بین فیلدها و دکمه
    MainView.HSplitTop(30.0f, &LoginButton, &MainView); // دکمه ورود

    // نمایش برچسب
    UI()->DoLabel(&Label, "Login Panel", 20.0f, TEXTALIGN_MC);

    // فیلد نام کاربری
    static char s_Username[64] = {0};
    UI()->DoEditBox(&s_Username, &UsernameBox, 12.0f);

    // فیلد رمز عبور
    static char s_Password[64] = {0};
    UI()->DoEditBox(&s_Password, &PasswordBox, 12.0f, true); // true برای مخفی کردن متن

    // دکمه ورود
    if (UI()->DoButton_Menu(&LoginButton, "Login", 0, TEXTALIGN_MC))
    {
        // در اینجا می‌توانید عملیات لاگین را انجام دهید
        // مثلاً بررسی نام کاربری و رمز عبور
        if (strcmp(s_Username, "admin") == 0 && strcmp(s_Password, "1234") == 0)
        {
            // اگر نام کاربری و رمز عبور صحیح بود
            dbg_msg("Login", "Login successful!");
        }
        else
        {
            // اگر نام کاربری یا رمز عبور اشتباه بود
            dbg_msg("Login", "Login failed!");
        }
    }
}
