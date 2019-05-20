/*************************************************************************
* File Name: TestLog4cpp3.cc
* Author: BAMBOO
* mail: jia@qq.com
* Created Time: Sun 19 May 2019 11:52:57 PM CST
 ************************************************************************/
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>

#include<iostream>

using std::cout;
using std::endl;
using namespace log4cpp;

int main(void)
{
    PatternLayout * patternLayout1 = new PatternLayout();
    patternLayout1->setConversionPattern("%d [%p] %m%n");
    
    PatternLayout * patternLayout2 = new PatternLayout();
    patternLayout2->setConversionPattern("%d [%p] %m%n");
    
    PatternLayout * patternLayout3 = new PatternLayout();
    patternLayout3->setConversionPattern("%d [%p] %m%n");
    
    
    return 0;
}

