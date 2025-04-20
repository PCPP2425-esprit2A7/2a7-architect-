/****************************************************************************
** Meta object code from reading C++ file 'gclinet.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../gclinet.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gclinet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSGclinetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSGclinetENDCLASS = QtMocHelpers::stringData(
    "Gclinet",
    "on_validerClient_clicked",
    "",
    "onTriChanged",
    "on_tableView_clicked",
    "QModelIndex",
    "index",
    "on_buttonModifier_clicked",
    "on_buttonSupprimer_clicked",
    "on_buttonAnnuler_clicked",
    "on_exportPdfButton_clicked",
    "afficherStatistiquesCompletes",
    "envoyerEmail",
    "nom",
    "prenom",
    "email",
    "nomProjet"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGclinetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    1,   70,    2, 0x08,    3 /* Private */,
       7,    0,   73,    2, 0x08,    5 /* Private */,
       8,    0,   74,    2, 0x08,    6 /* Private */,
       9,    0,   75,    2, 0x08,    7 /* Private */,
      10,    0,   76,    2, 0x08,    8 /* Private */,
      11,    0,   77,    2, 0x08,    9 /* Private */,
      12,    4,   78,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   13,   14,   15,   16,

       0        // eod
};

Q_CONSTINIT const QMetaObject Gclinet::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSGclinetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGclinetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGclinetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Gclinet, std::true_type>,
        // method 'on_validerClient_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTriChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableView_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_buttonModifier_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_buttonSupprimer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_buttonAnnuler_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_exportPdfButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherStatistiquesCompletes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'envoyerEmail'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void Gclinet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Gclinet *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_validerClient_clicked(); break;
        case 1: _t->onTriChanged(); break;
        case 2: _t->on_tableView_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 3: _t->on_buttonModifier_clicked(); break;
        case 4: _t->on_buttonSupprimer_clicked(); break;
        case 5: _t->on_buttonAnnuler_clicked(); break;
        case 6: _t->on_exportPdfButton_clicked(); break;
        case 7: _t->afficherStatistiquesCompletes(); break;
        case 8: _t->envoyerEmail((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObject *Gclinet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Gclinet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGclinetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Gclinet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
