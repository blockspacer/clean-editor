#pragma once

#include <QObject>
#include <vector>
#include <algorithm>

namespace CleanEditor {
namespace Util {

class TestRunner  {

public:
   static TestRunner & instance();

   template <class T>
   T & addTest() {
     static T test;
     auto it = std::find(tests_.cbegin(), tests_.cend(), &test);
     if (it == tests_.cend()) {
      tests_.emplace_back(&test);
     }
     return test;
   }
   int execTests(int argc = 0, char **argv = nullptr);

private:
   TestRunner() {}
   std::vector<QObject*> tests_;

};
} //namespace Util
} //namespace CleanEditor

#define ADD_TEST_CLASS(Class) \
  static Class& test_##Class = CleanEditor::Util::TestRunner::instance().addTest<Class>()

#define RUN_TESTS_MAIN \
  int main(int argc, char** argv) { \
    return CleanEditor::Util::TestRunner::instance().execTests(argc, argv); \
  }
