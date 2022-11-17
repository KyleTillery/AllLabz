#include "party.h"
#include "IRace.h"

class Ijob;
Party::Party()
{
}  // end default constructor


Party::Party(const std::shared_ptr<Ijob> theItem) : m_Main(theItem)
{
}  // end constructor


void Party::setMain(const std::shared_ptr<Ijob> theItem)
{
    m_Main = theItem;
}  // end setItem


std::shared_ptr<Ijob> Party::getMain() const
{
   return m_Main;
}  // end getItem


void Party::addMember(const std::shared_ptr<Ijob> theItem)
{ 
    m_Members.push_back(theItem);
}

std::vector<std::shared_ptr<Ijob>> Party::getMember()
{
    return m_Members;
}