namespace boilerplate {
  #define EMPTY(...)
  #define DEFER(...) __VA_ARGS__ EMPTY()
  #define EXPAND(...) __VA_ARGS__
  #define PARENS ()
  #define STRINGIFY_IMPL(...) #__VA_ARGS__
  #define STRINGIFY(...) STRINGIFY_IMPL(__VA_ARGS__)
  #define CONCAT_IMPL(L, R) L ## R
  #define CONCAT(L, R) CONCAT_IMPL(L, R)
  #define EVAL(...) __VA_ARGS__
  #define EVAL_1(...) __VA_ARGS__
  #define EVAL_1_1(...) __VA_ARGS__
  #define EVAL_1_2(...) __VA_ARGS__
  #define EVAL_1_3(...) __VA_ARGS__
  #define EVAL_2(...) EVAL_1(EVAL_1(__VA_ARGS__))
  #define EVAL_4(...) EVAL_2(EVAL_2(__VA_ARGS__))
  #define EVAL_8(...) EVAL_4(EVAL_4(__VA_ARGS__))
  #define EVAL_16(...) EVAL_8(EVAL_8(__VA_ARGS__))
  #define EVAL_32(...) EVAL_16(EVAL_16(__VA_ARGS__))
  #define EVAL_64(...) EVAL_32(EVAL_32(__VA_ARGS__))
  #define EVAL_128(...) EVAL_64(EVAL_64(__VA_ARGS__))
  #define EVAL_256(...) EVAL_128(EVAL_128(__VA_ARGS__))
  #define EVAL_512(...) EVAL_256(EVAL_256(__VA_ARGS__))
  #define EVAL_1024(...) EVAL_512(EVAL_512(__VA_ARGS__))
  #define EVAL_2048(...) EVAL_1024(EVAL_1024(__VA_ARGS__))
  #define EVAL_4096(...) EVAL_2048(EVAL_2048(__VA_ARGS__))
  #define EVAL_8192(...) EVAL_4096(EVAL_4096(__VA_ARGS__))
  #define FOR_EACH_64(MACRO, ...) EVAL_64(FOR_EACH_IMPL(MACRO, __VA_ARGS__))
  #define FOR_EACH_128(MACRO, ...) EVAL_128(FOR_EACH_IMPL(MACRO, __VA_ARGS__))
  #define FOR_EACH_256(MACRO, ...) EVAL_256(FOR_EACH_IMPL(MACRO, __VA_ARGS__))
  #define FOR_EACH_512(MACRO, ...) EVAL_512(FOR_EACH_IMPL(MACRO, __VA_ARGS__))
  #define FOR_EACH_1024(MACRO, ...) EVAL_1024(FOR_EACH_IMPL(MACRO, __VA_ARGS__))
  #define FOR_EACH(MACRO, ...) EVAL_1024(FOR_EACH_IMPL(MACRO, __VA_ARGS__))
  #define FOR_EACH_NEXT() FOR_EACH_IMPL
  #define FOR_EACH_IMPL(MACRO, ARG1, ...) MACRO(ARG1)__VA_OPT__(FOR_EACH_NEXT PARENS (MACRO, __VA_ARGS__))
  #define SELECT(FIRST, ...) FIRST
  #define SELECT_SECOND(FIRST, ...) __VA_ARGS__
  #define DISCARD_1(FIRST, ...) SELECT##__VA_OPT__(_SECOND)(FIRST, __VA_ARGS__)
  #define DISCARD_2(...) EVAL(DEFER(DISCARD_1)(DISCARD_1(__VA_ARGS__)))
  #define DISCARD_3(...) EVAL(DEFER(DISCARD_1)(DISCARD_2(__VA_ARGS__)))
  #define DISCARD_4(...) EVAL(DEFER(DISCARD_1)(DISCARD_3(__VA_ARGS__)))
  #define DISCARD_5(...) EVAL(DEFER(DISCARD_1)(DISCARD_4(__VA_ARGS__)))
  #define DISCARD_6(...) EVAL(DEFER(DISCARD_1)(DISCARD_5(__VA_ARGS__)))
  #define DISCARD_7(...) EVAL(DEFER(DISCARD_1)(DISCARD_6(__VA_ARGS__)))
  #define DISCARD_8(...) EVAL(DEFER(DISCARD_1)(DISCARD_7(__VA_ARGS__)))
  #define DISCARD_9(...) EVAL(DEFER(DISCARD_1)(DISCARD_8(__VA_ARGS__)))
  #define DISCARD_10(...) EVAL(DEFER(DISCARD_1)(DISCARD_9(__VA_ARGS__)))
  #define DISCARD_16(...) EVAL_8(DEFER(DISCARD_8)(DISCARD_8(__VA_ARGS__)))
  #define DISCARD_32(...) EVAL_16(DEFER(DISCARD_16)(DISCARD_16(__VA_ARGS__)))
  #define DISCARD_64(...) EVAL_32(DEFER(DISCARD_32)(DISCARD_32(__VA_ARGS__)))
  #define DISCARD_128(...) EVAL_64(DEFER(DISCARD_64)(DISCARD_64(__VA_ARGS__)))
  #define DISCARD_256(...) EVAL_128(DEFER(DISCARD_128)(DISCARD_128(__VA_ARGS__)))
  #define DISCARD_512(...) EVAL_256(DEFER(DISCARD_256)(DISCARD_256(__VA_ARGS__)))
  #define DISCARD_1024(...) EVAL_512(DEFER(DISCARD_512)(DISCARD_512(__VA_ARGS__)))
  #define REMOVE_PARENTHESES_IMPL(ARG, _, ...) __VA_OPT__(EVAL) ARG
  #define REMOVE_PARENTHESES(ARG) EVAL_1(DEFER(REMOVE_PARENTHESES_IMPL)(ARG, CHECK_PARENTHESES ARG))
  #define CHECK_PARENTHESES(...) _, __VA_ARGS__
  #define MAKE_HELPER_STRUCT(COUNTER, ...) template<EVAL_1024(MAKE_HELPER_STRUCT_IMPL(COUNTER, __VA_ARGS__))
  #define MEMBER_POINTER_CONCAT(_, ...) FOR_EACH_256(MEMBER_POINTER_CONCAT_ONCE, __VA_ARGS__)
  #define MEMBER_POINTER_CONCAT_ONCE(ARG) auto EVAL_1_1(DEFER(DISCARD_1)(REMOVE_PARENTHESES(ARG))), EMPTY()
  #define MAKE_HELPER_STRUCT_IMPL(COUNTER, ARG1, ...) EVAL_1_2(DEFER(MAKE_HELPER_STRUCT_IMPL_DISPATCH)(COUNTER, ARG1, (__VA_ARGS__), CHECK_PARENTHESES ARG1))
  #define MAKE_HELPER_STRUCT_IMPL_DISPATCH(COUNTER, ARG1, ARGS, _, ...) MAKE_HELPER_STRUCT_IMPL_TASK##__VA_OPT__(_EXEC)(COUNTER, CONCAT(ARG1, EVAL ARGS), __VA_ARGS__) __VA_OPT__(MAKE_HELPER_STRUCT_NEXT PARENS (COUNTER, EVAL ARGS))
  #define MAKE_HELPER_STRUCT_IMPL_TASK(COUNTER, FUNCTIONS, ...) void *> struct communist_function_helper_##COUNTER { FUNCTIONS };
  #define MAKE_HELPER_STRUCT_IMPL_TASK_EXEC(_1, _2, ...) MEMBER_POINTER_CONCAT(__VA_ARGS__)
  #define MAKE_HELPER_STRUCT_NEXT() MAKE_HELPER_STRUCT_IMPL
  #define CLASS_CONCAT(CLASS, ...) EVAL_256(CLASS_CONCAT_IMPL(CLASS, __VA_ARGS__))
  #define CLASS_CONCAT_IMPL(CLASS, ARG1, ...) &CLASS::EVAL(DEFER(SELECT)(REMOVE_PARENTHESES(ARG1))), __VA_OPT__(CLASS_CONCAT_NEXT PARENS (CLASS, __VA_ARGS__))
  #define CLASS_CONCAT_NEXT() CLASS_CONCAT_IMPL
  #define MAKE_TEMPLATE_INST(COUNTER, ...) template struct communist_function_helper_##COUNTER<EVAL_1024(MAKE_TEMPLATE_INST_IMPL(__VA_ARGS__)) nullptr>
  #define MAKE_TEMPLATE_INST_IMPL(ARG1, ...) EVAL_1_1(DEFER(MAKE_TEMPLATE_INST_IMPL_DISPATCH)((__VA_ARGS__), CHECK_PARENTHESES ARG1))
  #define MAKE_TEMPLATE_INST_IMPL_DISPATCH(ARGS, _, ...) MAKE_TEMPLATE_INST_IMPL_TASK##__VA_OPT__(_EXEC)(__VA_ARGS__) __VA_OPT__(MAKE_TEMPLATE_INST_NEXT PARENS ARGS)
  #define MAKE_TEMPLATE_INST_IMPL_TASK(...)
  #define MAKE_TEMPLATE_INST_IMPL_TASK_EXEC(...) CLASS_CONCAT(__VA_ARGS__)
  #define MAKE_TEMPLATE_INST_NEXT() MAKE_TEMPLATE_INST_IMPL
  #define DEFINE_COMMUNIST_FUNCTIONS(...) DEFINE_COMMUNIST_FUNCTIONS_IMPL(__COUNTER__, __VA_ARGS__);
  #define DEFINE_COMMUNIST_FUNCTIONS_IMPL(COUNTER, ...) MAKE_HELPER_STRUCT(COUNTER, __VA_ARGS__) MAKE_TEMPLATE_INST(COUNTER, __VA_ARGS__)
} // end namespace boilerplate

#include <iostream>

class Bourgeois {
private:
  class BankAccount {
    int money = 99999999;
  } bank_account;
  int social_credit = 0;
protected:
  std::string name;
public:
  Bourgeois(std::string name) : name(std::move(name)) {}
};

void commit_forced_expropriation(Bourgeois &);
void info(const Bourgeois &);

#define comrade friend
DEFINE_COMMUNIST_FUNCTIONS((Bourgeois, name, bank_account, social_credit), (Bourgeois::BankAccount, money),
  comrade void commit_forced_expropriation(Bourgeois &guy) {
    guy.*bank_account.*money = std::min(0, guy.*bank_account.*money);
    guy.*social_credit += 15;
  }
  comrade void info(const Bourgeois &guy) {
    std::cout << "           Name : " << guy.*name << '\n';
    std::cout << "          Money : " << guy.*bank_account.*money << (guy.*bank_account.*money > 0 ? " 👎" : " ✅") << '\n';
    std::cout << "  Social Credit : " << guy.*social_credit << (guy.*social_credit <= 0 ? " 😡😡👎👎👎" : " ✅") << '\n';
  }
)

int main() {
  Bourgeois john("John");
  std::cout << "Before:\n";
  info(john);
  commit_forced_expropriation(john);
  std::cout << "\nAfter:\n";
  info(john);
}
