/****************************************************************************
** Resource object code
**
** Created: Mon May 13 11:51:43 2013
**      by: The Resource Compiler for Qt version 4.8.1
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtCore/qglobal.h>

static const unsigned char qt_resource_data[] = {
  // E:/Workspace/Qt/OOPS/MainWindow/resources/category.txt
  0x0,0x0,0x0,0x1f,
  0x43,
  0x20,0x50,0x72,0x6f,0x67,0x72,0x61,0x6d,0x6d,0x69,0x6e,0x67,0xd,0xa,0x4a,0x61,
  0x76,0x61,0x20,0x50,0x72,0x6f,0x67,0x72,0x61,0x6d,0x6d,0x69,0x6e,0x67,
  
};

static const unsigned char qt_resource_name[] = {
  // resources
  0x0,0x9,
  0xa,0x6c,0x78,0x43,
  0x0,0x72,
  0x0,0x65,0x0,0x73,0x0,0x6f,0x0,0x75,0x0,0x72,0x0,0x63,0x0,0x65,0x0,0x73,
    // category.txt
  0x0,0xc,
  0xb,0xad,0xc,0x34,
  0x0,0x63,
  0x0,0x61,0x0,0x74,0x0,0x65,0x0,0x67,0x0,0x6f,0x0,0x72,0x0,0x79,0x0,0x2e,0x0,0x74,0x0,0x78,0x0,0x74,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
  // :/resources
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
  // :/resources/category.txt
  0x0,0x0,0x0,0x18,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,

};

QT_BEGIN_NAMESPACE

extern Q_CORE_EXPORT bool qRegisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

extern Q_CORE_EXPORT bool qUnregisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

QT_END_NAMESPACE


int QT_MANGLE_NAMESPACE(qInitResources_MainWindow)()
{
    QT_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_MainWindow))

int QT_MANGLE_NAMESPACE(qCleanupResources_MainWindow)()
{
    QT_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_DESTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qCleanupResources_MainWindow))

