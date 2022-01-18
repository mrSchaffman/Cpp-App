#include "DvD.h"

DvD::DvD(wxString title, wxString star1, wxString star2, wxString producer, wxString director, wxString productionCom, size_t setInStock) :wxListItem()
{
	setDVDInfo(title, star1, star2, producer, director, productionCom, setInStock);
	

	//from the wxListItem
	//SetId(DvDid++);
	//SetFont(*wxITALIC_FONT);
	//SetTextColour(*wxBLACK);
	//SetStateMask(wxLIST_STATE_SELECTED);
	//SetState(wxLIST_STATE_SELECTED);
}

void DvD::setDVDInfo(wxString & title, wxString & star1, wxString & star2, wxString & producer, wxString & director, wxString & productionCo, int setInStock)
{

	m_dvdTitle = title;
	m_movieStar1 = star1;
	m_movieStar2 = star2;
	m_movieProducer = producer;
	m_productionCompagnie = productionCo;
	m_movieDirector = director;
	m_numberInStock = setInStock;

}

void DvD::checkOut()
{
	if (getNumOfCopiesInStock() > 0)
	{
		m_numberInStock--;
	}
	else
	{
		throw std::out_of_range("Currently Out of stock!");
	}

}

void DvD::chechIn()
{
	m_numberInStock++;
}

void DvD::updateNumOfCopiesInStock(size_t num)
{
	m_numberInStock = num;
}


bool DvD::operator==(const DvD & otherDVD) const
{
	return m_dvdTitle == otherDVD.getTitle();
}

bool DvD::operator!=(const DvD & otherDVD) const
{
	return m_dvdTitle != otherDVD.getTitle();
}

bool DvD::operator<=(const DvD & otherDVD) const
{
	return m_dvdTitle <= otherDVD.getTitle();
}

bool DvD::operator>=(const DvD & otherDVD) const
{
	return m_dvdTitle >= otherDVD.getTitle();
}

bool DvD::operator<(const DvD & otherDVD) const
{
	return m_dvdTitle < otherDVD.getTitle();
}

bool DvD::operator>(const DvD & otherDVD) const
{
	return m_dvdTitle > otherDVD.getTitle();
}

std::ostream & operator<<(std::ostream & oStream, const DvD & dvd)
{
	oStream << std::endl;
	oStream << "Title:" << std::endl;
	oStream << "Stars: " << dvd.getStar1() << " - " << dvd.getStar2() << std::endl;
	oStream << "Producer: " << dvd.getProducer() << std::endl;
	oStream << "Production Compagny: " << dvd.getProductionCompagnie() << std::endl;
	oStream << "Director: " << dvd.getDirector() << std::endl;
	oStream << "Total in Stock: " << dvd.getNumOfCopiesInStock() << std::endl;
	oStream << "_____________________________________________________" << std::endl;

	return oStream;
}
